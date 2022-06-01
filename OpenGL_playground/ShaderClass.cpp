
#include "ShaderClass.h"

std::string GetFileContents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string cont;
		in.seekg(0, std::ios::end);
		cont.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&cont[0], cont.size());
		in.close();
		return(cont);
	}
	throw(errno);
}

Shader::Shader(const char* VertShaderFile, const char* FragShaderFile)
{
	// getting the shader code from the file
	std::string VertCode = GetFileContents(VertShaderFile);
	std::string FragCode = GetFileContents(FragShaderFile);

	// storing the shader code in the string 
	const char* VertSource = VertCode.c_str();
	const char* FragSource = FragCode.c_str();

	// creating a value aka reference to store shader 
	// creating the vertex shader
	GLuint V_Vertex_Shader = glCreateShader(GL_VERTEX_SHADER);

	// referencing the V_VertexShader var to the source of vertex shader
	glShaderSource(V_Vertex_Shader, 1, &VertSource, NULL);

	// telling the compiler to compile the source code to machine code
	glCompileShader(V_Vertex_Shader);

	// creating the Fragment shader
	GLuint V_Fragment_Shader = glCreateShader(GL_FRAGMENT_SHADER);

	// referencing the V_FragmentShader var to the source of fragment shader
	glShaderSource(V_Fragment_Shader, 1, &FragSource, NULL);

	// telling the compiler to compile the source code to machine code
	glCompileShader(V_Fragment_Shader);

	// Linking the shaders in order to use them in a shader program
	// shader program is like a profile which is used to compute data using shaders
	// by this we can tell the GPU how to process the image 
	Profile_ShaderCLass = glCreateProgram();

	// Attaching the shaders to the program
	glAttachShader(Profile_ShaderCLass, V_Vertex_Shader);
	glAttachShader(Profile_ShaderCLass, V_Fragment_Shader);

	// to complete the profile or wraping up the shader program
	glLinkProgram(Profile_ShaderCLass);

	// deleting the created shaders since they are already present in the program
	glDeleteShader(V_Vertex_Shader);
	glDeleteShader(V_Fragment_Shader);
}

void Shader::Shader_Inst_Activate()
{
	glUseProgram(Profile_ShaderCLass);
}

void Shader::Shader_Inst_Delete()
{
	glDeleteProgram(Profile_ShaderCLass);
}
