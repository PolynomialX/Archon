#ifndef ARCHON_GENERAL_LOGGING_QUILL_LOGGER_H_
#define ARCHON_GENERAL_LOGGING_QUILL_LOGGER_H_

#include "general/logging/ILogger.h"
#include <memory>

namespace archon
{
namespace general
{
namespace logging
{
/**
 * @class QuillLogger
 * @brief Implementation of ILogger class
 *        that uses the Quill library
 */
class QuillLogger : public ILogger
{
public:
    /**
     * 
     */
    explicit QuillLogger(const std::string& loggerName_);
    ~QuillLogger();

    virtual void logInfo(const std::string& infoMsg_) override;
    virtual void logDebug(const std::string& debugMsg_) override;
    virtual void logTrace(const std::string& traceMsg_) override;
    virtual void logError(const std::string& errorMsg_) override;
    virtual void logFatal(const std::string& fatalMsg_) override;

private:
    class QuillLoggerImpl;
    std::unique_ptr<QuillLoggerImpl> pImpl;
};
} // logging
} // general
} // archon


#endif // ARCHON_GENERAL_LOGGING_QUILL_LOGGER_H_