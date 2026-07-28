#include "general/logging/QuillLogger.h"
#include "quill/Logger.h"
#include "quill/Frontend.h"
#include "quill/sinks/ConsoleSink.h"
#include "quill/LogMacros.h"
#include "quill/backend.h"
namespace archon
{
namespace general
{
namespace logging
{

class QuillLogger::QuillLoggerImpl
{
public:
    /**
     * @brief Constructor for QuillLoggerImpl
     *        Currently we're just logging to the terminal,
     *        So the arg to create_or_get_sink is generic
     */
    QuillLoggerImpl(const std::string& loggerHandle_)
    {
        // This needs to be called once...
        // so this needs to be in a logmanager class / factory class?
        quill::Backend::start();
        const std::string defaultConsoleSink = "CONSOLE_SINK";
        auto consoleSink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>(defaultConsoleSink);
        logger = 
            quill::v12::Frontend::create_or_get_logger(loggerHandle_, std::move(consoleSink));
    }

    ~QuillLoggerImpl()
    {
        
    }

    void logInfo(const std::string& infoMsg_)
    {
        LOG_INFO(logger, "Test");
    }

private:
// Needed as quill handles resources for loggerptr
    void customDelete()
    {
        // Do nothing - do not delete as Quill manages the pointer
    }
    quill::v12::Logger* logger;
};

QuillLogger::QuillLogger(const std::string& loggerHandle_):
    pImpl(std::make_unique<QuillLoggerImpl>(loggerHandle_))
{

}
QuillLogger::~QuillLogger()
{

}

void QuillLogger::logInfo(const std::string& infoMsg_)
{
    // pImpl->logInfo(infoMsg_);
}
void QuillLogger::logDebug(const std::string& debugMsg_)
{
    // pImpl->logDebug(debugMsg_);
}
void QuillLogger::logTrace(const std::string& traceMsg_)
{

}
void logError(const std::string& errorMsg_)
{

}
void QuillLogger::logFatal(const std::string& fatalMsg_)
{

}

} // logging
} // general
} // archon