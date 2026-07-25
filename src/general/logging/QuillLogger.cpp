#include "general/logging/QuillLogger.h"
#include "quill/Logger.h"
#include "quill/Frontend.h"
#include "quill/sinks/ConsoleSink.h"
namespace archon
{
namespace general
{
namespace logging
{

class QuillLoggerImpl
{
public:
    /**
     * @brief Constructor for QuillLoggerImpl
     *        Currently we're just logging to the terminal,
     *        So the arg to create_or_get_sink is generic
     */
    QuillLoggerImpl(const std::string& loggerHandle_)
    {
        auto consoleSink = quill::Frontend::create_or_get_sink<quill::Sink>("CONSOLE_SINK");
        logger = std::make_unique<quill::Logger>(quill::Frontend::create_or_get_logger(loggerHandle_, std::move(consoleSink)));
    }

private:
    std::unique_ptr<quill::Logger> logger;
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

}
void QuillLogger::logDebug(const std::string& debugMsg_)
{

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