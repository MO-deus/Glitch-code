
#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H	

#include<glad/glad.h>
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>
#include<cerrno>

std::string GetFileContents(const char* filename);

class Shader {
public:
	GLuint Profile_ShaderCLass{};
	Shader(const char* VertShaderFile, const char* FragShaderFile);
	//	Outputs the contents of given file in form of string

	void Shader_Inst_Activate();
	void Shader_Inst_Delete();
};

#endif // !SHADER_CLASS_H
