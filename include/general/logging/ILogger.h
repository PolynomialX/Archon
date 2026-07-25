#ifndef ARCHON_GENERAL_LOGGING_ILOGGER_H_
#define ARCHON_GENERAL_LOGGING_ILOGGER_H_

#include <string>

namespace archon
{
namespace general
{
namespace logging
{
/**
 * @class ILogger
 * @brief Interface for logging
 */
class ILogger
{
public:
    virtual void logInfo(const std::string& infoMsg_) = 0;
    virtual void logDebug(const std::string& debugMsg_) = 0;
    virtual void logTrace(const std::string& traceMsg_) = 0;
    virtual void logError(const std::string& errorMsg_) = 0;
    virtual void logFatal(const std::string& fatalMsg_) = 0;
};
} // logging
} // general
} // archon
#endif // ARCHON_GENERAL_LOGGING_ILOGGER_H_