shader_type canvas_item;

uniform float len = 0.10;
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
	
	float pix = 0.0;
	while(!threshold(vec2(SCREEN_UV.x, SCREEN_UV.y - pix)) && pix < len){
		pix += (SCREEN_PIXEL_SIZE.y);
		//if((SCREEN_UV.y - pix) < 0.0){
		//	pix = 1.0;
		//	break;
		//}
	}
	
	COLOR = texture(screen_texture, vec2(SCREEN_UV.x, SCREEN_UV.y - pix));
	//COLOR = vec4(pix, pix, pix, 1.0);
	//bool thresh = threshold(SCREEN_UV);
	//OLOR = vec4(float(thresh), float(thresh), float(thresh), 1.0);
}
