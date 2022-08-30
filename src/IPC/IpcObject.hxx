#ifndef WATCHDOG_IPCOBJECT_HXX
#define WATCHDOG_IPCOBJECT_HXX

#include <memory>
#include <utility>
#include <type_traits>
#include <unordered_map>

#include "Result.hxx"
#include "WdTypes.hxx"

namespace IpcDetails {
    template <typename Type, std::size_t IASize>
    class IpcClient {
    using IArray = std::array<Type, IASize>;
    private:
        String name;
        IArray buffer;
        usize  index {0};
        Type const *s_buffer; // This is where it is going to keep track of the data

    public:
        IpcClient() = default;

        explicit IpcClient(String c_name, Type *server_buffer) : name(std::move(c_name)), index(0) {
            if (server_buffer == nullptr) {
                // !TODO: Raise an error
            }
            s_buffer = server_buffer;
        }

        /**
         *
         * @return Returns a newly allocated value
         */
        [[nodiscard]] Type receive() const { return buffer[index]; }

        /**
         * Removes an element from the buffer. In addition to removing the element,
         */
        void remove() {

        }

        /**
         *
         * @return Name of the client
         */
        [[nodiscard]] String client_name() const { return name; }
    };

    template <typename Type>
    /**
     * Data inside this class are immutable from outside
     * In addition to that, the server class will be responsible for handing out client
     * object(s).
     * @tparam Type Type of object it will be managing
     * @tparam IASize Total amount of objects to accommodate. This number will be double for the server
     */
    class IpcServer {
    using IClient = IpcClient<Type, 8>;
    private:
        String                  s_name;
        std::shared_ptr<Type>   object;
        usize                   idx {0};
        std::unordered_map<String, IClient> clients;

        [[nodiscard]] Type *g_iarray() const noexcept { return object.get(); }

    public:
        IpcServer() = default;

        explicit IpcServer(String const &name) : s_name(name) {}

        /**
         * Send data to the shared state
         * @type: Data to send
         */
        void send(Type const &type) {
            if (not std::is_pointer<Type>::value) return;
            object = std::make_shared<Type>(type);
        } 

        [[nodiscard]] Result<IClient> subscribe(String const &client_name) const {
            const auto oobj = g_iarray();
			if (!oobj) return ReturnResult(IClient(), String("Subscriber object is no longer valid"));

			auto subobj = IClient(client_name, g_iarray());
			return ReturnResult(subobj, String());
		}
    };
}

#endif//WATCHDOG_IPCOBJECT_HXX
