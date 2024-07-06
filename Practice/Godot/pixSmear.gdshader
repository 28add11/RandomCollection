shader_type canvas_item;

uniform int length = -1;
uniform float lowThresh = 0.3;
uniform float highThresh = 0.8;

uniform sampler2D screen_texture : hint_screen_texture, repeat_disable, filter_nearest;

bool threshold(vec2 uv){
	
	float luminance;
	luminance = (texture(screen_texture, uv).r * 0.3) + (texture(screen_texture, uv).g * 0.59) + (texture(screen_texture, uv).b * 0.11);
	
	return luminance > lowThresh && luminance < highThresh;
}

void fragment() {
	// Called for every pixel the material is visible on.
	float luminance;
	luminance = (texture(screen_texture, SCREEN_UV).r * 0.3) + (texture(screen_texture, SCREEN_UV).g * 0.59) + (texture(screen_texture, SCREEN_UV).b * 0.11);
	
	
	COLOR = texture(screen_texture, SCREEN_UV);
}
