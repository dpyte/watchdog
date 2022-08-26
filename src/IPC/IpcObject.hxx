#ifndef WATCHDOG_IPCOBJECT_HXX
#define WATCHDOG_IPCOBJECT_HXX

#include <memory>
#include <utility>

#include "Result.hxx"
#include "WdTypes.hxx"

namespace IpcDetails {


    template <typename Type, std::size_t IASize>
    /**
     * Data inside this class are immutable from outside
     * In addition to that, the server class will be responsible for handing out client
     * object(s).
     * @tparam Type Type of object it will be managing
     * @tparam IASize Total amount of objects to accommodate. This number will be double for the server
     */
    class IpcServer {
    using IArray = std::array<Type, IASize * 2>;
    private:
        String s_name;
        std::unique_ptr<IArray> object;
        usize idx {0};

        [[nodiscard]] IArray *g_iarray() const noexcept {
            return object.get();
        }

    public:
        IpcServer() = default;
        explicit IpcServer(String name) : s_name(std::move(name)), idx(0) {
            object = std::make_unique<IArray>();
            if (not object) { /* Report accordingly */ }
        }

        explicit IpcServer(String &name): s_name(std::move(name)), idx(0) {
            object = std::make_unique<IArray>();
            if (not object) { /* Report accordingly */ }
        }

        void append_obj(Type obj) {
            if (idx >= IASize) idx = 0;
            g_iarray()[idx] = obj;
        }

        void append_obj(Type &obj) {
            if (idx >= IASize) idx = 0;
            g_iarray()[idx] = std::move(obj);
        }

        [[nodiscard]] usize size() const { return g_iarray()->size(); }
    };
}

#endif//WATCHDOG_IPCOBJECT_HXX
