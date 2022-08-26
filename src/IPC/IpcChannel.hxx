#ifndef WATCHDOG_IPCCHANNEL_HXX
#define WATCHDOG_IPCCHANNEL_HXX

#include <array>
#include <unordered_map>

#include "Result.hxx"
#include "WdTypes.hxx"
#include "IpcObject.hxx"

/**
 *             [*]
 *              |
 *             / \
 *            /   \
 *         [=]     [=]
 *
 */

namespace Ipc {
    template <typename Type, std::size_t BufSize>
    class Channel {
    private:
        static std::unordered_map<String, IpcDetails::IpcServer<Type, BufSize>> keepsafe;

    public:
        Channel() = default;

        /**
         * Create a new object using default allocation size
         * @param name Name of the server
         */
        static void NewServer(String const &name) {
            static const usize iarraysize = 16;
            auto n_object = IpcDetails::IpcServer<Type, BufSize>(name);
            keepsafe[name] = std::move(n_object);
        }
    };
} // namespace Ipc


#endif//WATCHDOG_IPCCHANNEL_HXX
