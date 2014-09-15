#include <QApplication>
#include <QDebug>
#include <QFile>
#include <unistd.h>
#include <fcntl.h>
#include <strings.h>
#include <getopt.h>
#include "common.hh"


_INITIALIZE_EASYLOGGINGPP

#define CAPTURE_LOAD_TIMEOUT        1000*10
#define CAPTURE_MAX_MEMORY          1024*1024*100
#define CAPTURE_LOGGING_FILE        "logging.conf"

void printHelp(char **argv);
void printVersion();
char* checkPidFile(char *pidFile, FILE *pidFp);


int main(int argc, char **argv)
{
    if(!QFile::exists(QString(CAPTURE_LOGGING_FILE)))
    {
        printf("Logging conf file is not exists, %s.", CAPTURE_LOGGING_FILE);
        exit(-1);
    }

    el::Configurations c(CAPTURE_LOGGING_FILE);
    el::Loggers::reconfigureLogger("default", c);
    el::Loggers::reconfigureAllLoggers(c);

    static struct option long_options[] =
    {
        {"help",                no_argument,        0,  'h'},
        {"version",             no_argument,        0,  'v'},
        {"pid-file",            required_argument,  0,  'p'},
        {"load-timeout",        required_argument,  0,  't'},
        {"max-memory",          required_argument,  0,  'm'},
        {0, 0, 0, 0}
    };

    char *pidFile = NULL;
    int loadTimeout = CAPTURE_LOAD_TIMEOUT;
    qint64 maxMemory = CAPTURE_MAX_MEMORY;
    FILE *pid = NULL;

    int option_index = 0;
    int opt = 0;

    while(1)
    {
        opt = getopt_long(argc, argv, "hvp:t:m:", long_options, &option_index);
        if (opt == -1)
            break;

        switch(opt)
        {
            case 'h':
                printHelp(argv);
                break;
            case 'v':
                printVersion();
                break;
            case 'p':
                pidFile = checkPidFile(optarg, pid);
                break;
            case 't':
                loadTimeout = atoi(optarg) * 1000;
                break;
            case 'm':
                maxMemory = (qint64)atoi(optarg) * 1024 * 1024;
                break;
            default:

                break;
        }
    }

    LOG(DEBUG) << "Conf : load timeout " << loadTimeout << " ms";
    LOG(DEBUG) << "Conf : max memory " << loadTimeout << " bytes";

    QApplication app(argc, argv);
    QApplication::setApplicationName("screenshot");
    QApplication::setApplicationVersion("0.1");

    LOG(INFO) << "Start application";

    Redis redis("192.168.3.5", 6379);
    WebViewRemoveQue removeQue(5);
    WebViewRemover remover(&removeQue, 1000);
    remover.start();
    if(!redis.connect())
    {
        LOG(FATAL) << "Cannot connect to redis.";
        exit(-1);
    }

    LOG(INFO) << "Redis connected successfully.";
    Capture capture(&app, &redis, &removeQue, maxMemory, loadTimeout);
    capture.start();

    return app.exec();
}

void printHelp(char **argv)
{
    printf("\n");
    printf("Usage: %s LOGGING_CONF_PATH [options] \n", argv[0]);
    printf("  LOGGING_CONF_PATH             logging configuration file.\n");
    printf("  options:\n");
    printf("    m | max-memory=SIZE         MB(MegaByte), memory usage limitation.\n");
    printf("    t | load-timeout=SECONDS    Seconds, page loading timeout.\n");
    printf("    p | pid-file=PATH           Pid file path.\n");
    exit(0);
}

void printVersion()
{
    printf("snapshot:%d.%d.%d", VER_MAJOR, VER_MINOR, VER_PATCH);
    exit(0);
}

char* checkPidFile(char *pidFile, FILE *pidFp)
{
    int fd, res;
    pid_t pid = getpid();
    struct flock flock;


    pidFp = fopen(pidFile, "r+");
    if(pidFp == NULL)
    {
        pidFp = fopen(pidFile, "w");
        if(pidFp == NULL)
        {
            printf("Cannot open pid file %s %s", pidFile, strerror(errno));
            exit(-1);
        }
    }

    fd = fileno(pidFp);

    memset(&flock, 0x00, sizeof(struct flock));
    flock.l_type = F_WRLCK;

    res = fcntl(fd, F_SETLK, &flock);
    if(res < 0)
    {
        printf("Error, another zoodis process is running. PID:%s", pidFile);
        fclose(pidFp);
        exit(-1);
    }

    fseek(pidFp, 0L, SEEK_SET);
    res = fprintf(pidFp, "%d", pid);
    res = ftruncate(fd, (off_t)ftell(pidFp));
    fflush(pidFp);
    return pidFile;
}
