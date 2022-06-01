
#ifndef _VBO_CLASS_H
#define _VBO_CLASS_H

#include <glad/glad.h>

class VBO
{
public:

	// Buffer for loading the verices data 
	// VBO [ Visual Buffer Object  ] stores the data of verices
	GLuint Profile_VBO{}; 

	// constructs the VBO buffer
	VBO(GLfloat* vertices, GLsizeiptr size_VBO);
	
	void bind_VBO();
	void unbind_VBO();
	void Delete_VBO();
};

#endif // !_VBO_CLASS_H
