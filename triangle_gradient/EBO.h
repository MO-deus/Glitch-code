
#ifndef _EBO_CLASS_H
#define _EBO_CLASS_H	

#include <glad/glad.h>

class EBO
{
public:

	// Buffer for loading the indices of vertices 
	// EBO [ Element Buffer Object  ] stores the indices
	GLuint Profile_EBO{};

	// constructs the EBO buffer
	EBO(GLuint* indices, GLsizeiptr size_EBO);

	void bind_EBO();
	void unbind_EBO();
	void Delete_EBO();
};

#endif // !_EBO_CLASS_H
