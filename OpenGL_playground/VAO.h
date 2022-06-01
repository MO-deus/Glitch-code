
#ifndef _VAO_CLASS_H
#define _VAO_CLASS_H

#include "VBO.h"

class VAO
{
public :
	GLuint Profile_VAO{};

public :
	VAO();
	void LinkAttrib(VBO , GLuint, GLuint, GLenum, GLsizeiptr, void* );
	void bind_VAO();
	void unbind_VAO();
	void Delete_VAO();
};

#endif // !_VAO_CLASS_H
