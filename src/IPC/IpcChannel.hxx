#ifndef WATCHDOG_IPCCHANNEL_HXX
#define WATCHDOG_IPCCHANNEL_HXX

#include <array>

#include "WdTypes.hxx"

namespace {
    template <typename Type>
    class RSObject {
    protected:
        Type    *object;
        usize   _index;
        usize   _size;

    public:
        /**
         * Allocate underlying memory object of type `Type` of size `_size`
         * @param size
         */
        explicit RSObject(usize size) : _index(0), _size(size) {
            object = new Type[size];
        }

        [[nodiscard]] usize index() const { return _index; }
        [[nodiscard]] usize size()  const { return _size; }
    };

    template <typename Type>
    class Sender : protected RSObject<Type> {
    private:

    };

    template <typename Type>
    class Receiver : protected RSObject<Type> {
    private:

    };
}

namespace Ipc {
    template <typename Type, std::size_t BufSize>
    class Channel {
    private:
        String _name;

    public:
        Channel() = delete;
        explicit Channel(String name) : _name(std::move(name)) {
        }
    };
} // namespace Ipc


#endif//WATCHDOG_IPCCHANNEL_HXX
