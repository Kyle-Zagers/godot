#include "servers/physics_server_2d.h"
#include "servers/physics_server_3d.h"

class physics {
    static PhysicsServer3DManager *physics_server_3d_manager = nullptr;
    static PhysicsServer3D *physics_server_3d = nullptr;
    static PhysicsServer2DManager *physics_server_2d_manager = nullptr;
    static PhysicsServer2D *physics_server_2d = nullptr;

    static void initialize_physics();
    static void finalize_physics();
}