#ifndef __core_h__
#define __core_h__

#include "api.h"

namespace tcore {
    using namespace api;

    class core : public iCore {
    public:
        virtual ~core() {}
        void parseArgs(int argc, const char ** argv);
        virtual const char * getArgs(const char * name);

        virtual void setCorename(const char * name) { _core_name = name; }
        virtual const char * getCorename() { return _core_name.c_str(); }

        static core * getInstance();
        virtual bool launchUdpSession(iUdpSession * session, const char * ip, const s32 port);
        virtual bool launchTcpSession(iTcpSession * session, const char * ip, const int port, int max_ss, int max_rs);
        virtual bool launchTcpServer(iTcpServer * server, const char * ip, const int port, int max_ss, int max_rs);


        virtual void startTimer(iTimer * timer, const s32 id, s64 delay, s32 count, s64 interval, const iContext context, const char * file, const s32 line);
        virtual void killTimer(iTimer * timer, const s32 id, const iContext context = (s64)0);
        virtual void pauseTimer(iTimer * timer, const s32 id, const iContext context = (s64)0);
        virtual void resumeTimer(iTimer * timer, const s32 id, const iContext context = (s64)0);
        virtual void traceTimer();
        
        virtual void logSync(const s64 tick, const char * log, const bool echo);
        virtual void logAsync(const s64 tick, const char * log, const bool echo);
        virtual void setSyncFilePrefix(const char * prefix);
        virtual void setAsyncFilePrefix(const char * prefix);

        void loop();
    private:
        std::string _core_name;
    };
}

#endif //__core_h__
