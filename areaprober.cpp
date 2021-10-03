#include "AreaProber.h"
#include "core/engine.h"
#include "scene/resources/world_2d.h"
#include "servers/physics_2d_server.h"
Array AreaProber::probe(Vector2 position) {
 	Vector<Physics2DDirectSpaceState::ShapeResult> results;
 	Physics2DDirectSpaceState *space_state = get_world_2d()->get_direct_space_state();
 	Transform2D t;
	t.set_origin(position);
	t.set_rotation_and_scale(0, Vector2(1,1));
	results.resize(32);
	Array ret;
	int collisions = space_state->intersect_shape(get_collision_shape()->get_rid(), t, Vector2(0,0), 0, results.ptrw(), results.size(), Set<RID>(), get_collision_mask(), get_collision_detect_bodies(), get_collision_detect_areas());
 	if (collisions > 0){
		ret.resize(collisions);
		for (int c = 0; c < collisions; c++){
			Array collider_and_shape;
			collider_and_shape.resize(2);
			collider_and_shape[0] = results[c].collider;
			collider_and_shape[1] = results[c].shape;
			ret[c] = collider_and_shape;
		}
	}
 	return ret;
}
void AreaProber::set_collision_shape(const Ref<Shape2D> &p_shape) {
	collision_shape = p_shape;
}

Ref<Shape2D> AreaProber::get_collision_shape() const {
	return collision_shape;
}

void AreaProber::set_collision_mask(int p_mask) {
	collision_mask = p_mask;
}

int AreaProber::get_collision_mask() const {
	return collision_mask;
}

void AreaProber::set_collision_detect_bodies(bool p_enabled) {
	collision_detect_bodies = p_enabled;
}

bool AreaProber::get_collision_detect_bodies() const {
	return collision_detect_bodies;
}

void AreaProber::set_collision_detect_areas(bool p_enabled) {
	collision_detect_areas = p_enabled;
}

bool AreaProber::get_collision_detect_areas() const {
	return collision_detect_areas;
}
void AreaProber::_bind_methods(){
	ClassDB::bind_method(D_METHOD("probe", "position"), &AreaProber::probe);
	ClassDB::bind_method(D_METHOD("set_collision_shape", "collision_shape"), &AreaProber::set_collision_shape);
	ClassDB::bind_method(D_METHOD("get_collision_shape"), &AreaProber::get_collision_shape);

	ClassDB::bind_method(D_METHOD("set_collision_mask", "collision_mask"), &AreaProber::set_collision_mask);
	ClassDB::bind_method(D_METHOD("get_collision_mask"), &AreaProber::get_collision_mask);

	ClassDB::bind_method(D_METHOD("set_collision_detect_bodies", "enabled"), &AreaProber::set_collision_detect_bodies);
	ClassDB::bind_method(D_METHOD("get_collision_detect_bodies"), &AreaProber::get_collision_detect_bodies);

	ClassDB::bind_method(D_METHOD("set_collision_detect_areas", "enabled"), &AreaProber::set_collision_detect_areas);
	ClassDB::bind_method(D_METHOD("get_collision_detect_areas"), &AreaProber::get_collision_detect_areas);
}


AreaProber::AreaProber(){
	collision_shape = Ref<Shape2D>();
	collision_mask = 1;
	collision_detect_bodies = true;
	collision_detect_areas = true;
}
