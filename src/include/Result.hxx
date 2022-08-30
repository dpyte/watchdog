#ifndef WATCHDOG_RESULT_HXX
#define WATCHDOG_RESULT_HXX

#include <utility>
#include <optional>
#include <exception>

#include "WdTypes.hxx"

namespace WdResult {
    struct Err : public std::exception {
    protected:
        String _msg;

    public:
        explicit Err(char const *message) : _msg(message) {}
        explicit Err(String message) : _msg(std::move(message)) {}
        explicit Err(String const &message): _msg(message) {}

        ~Err() noexcept override = default;
        virtual const char *what() { return _msg.c_str(); }
    };

    struct ParsingErr: protected Err {
        explicit ParsingErr(char const *message) : Err(message) {}
    };
}

template <typename Type, typename Error = String>
using Result = std::pair<std::optional<Type>, Error>;

template <typename Type, typename Error = String>
inline Result<Type, Error> ReturnResult(Type type, String msg) {
    return std::make_pair(std::optional(type), String(std::move(msg)));
}

/**
 * Check whether the Result contains any error or not
 * @tparam Type
 * @param err
 * @return True if it contains error else false indicating no error
 */
template <typename Type>
inline bool CheckError(Result<Type, String> const &err) { return !err.second.empty(); }

template <typename Type>
inline Type ResultObject(Result<Type, String> const &robj) { return std::move(*robj.first); }

template <typename Type>
inline String ResultMessage(Result<Type, String> const &obj) { return obj.second; }

#endif//WATCHDOG_RESULT_HXX
