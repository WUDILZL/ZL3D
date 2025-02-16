#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

//out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float migration;//Éî¶ÈÆ«ÒÆ

void main()
{
	gl_Position = vec4(aPos, 1.0f) * model * view * projection;
	vec4 Depth = vec4(0.0f, 0.0f, migration, 1.0f) * projection;
	gl_Position.z += Depth.z;
	//TexCoord = vec2(aTexCoord.x, aTexCoord.y); //ÑÕÉ«
}