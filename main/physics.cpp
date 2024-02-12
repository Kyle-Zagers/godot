#include "physics.h"

static void physics::initialize_physics() {
	/// 3D Physics Server
	physics_server_3d = PhysicsServer3DManager::get_singleton()->new_server(
			GLOBAL_GET(PhysicsServer3DManager::setting_property_name));
	if (!physics_server_3d) {
		// Physics server not found, Use the default physics
		physics_server_3d = PhysicsServer3DManager::get_singleton()->new_default_server();
	}
	ERR_FAIL_NULL(physics_server_3d);
	physics_server_3d->init();

	// 2D Physics server
	physics_server_2d = PhysicsServer2DManager::get_singleton()->new_server(
			GLOBAL_GET(PhysicsServer2DManager::get_singleton()->setting_property_name));
	if (!physics_server_2d) {
		// Physics server not found, Use the default physics
		physics_server_2d = PhysicsServer2DManager::get_singleton()->new_default_server();
	}
	ERR_FAIL_NULL(physics_server_2d);
	physics_server_2d->init();
}

static void physics::finalize_physics() {
	physics_server_3d->finish();
	memdelete(physics_server_3d);

	physics_server_2d->finish();
	memdelete(physics_server_2d);
}