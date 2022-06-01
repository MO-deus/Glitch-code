
#include "VAO.h"

VAO::VAO()
{	
	// returns vertex array object(s)
	glGenVertexArrays(1, &Profile_VAO);
}

void VAO::LinkAttrib(VBO VBO_obj, GLuint layout, GLuint NumComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	// starts binding VBO
	VBO_obj.bind_VBO();
	
	// normalizes the data to floating point 
	glVertexAttribPointer(layout, NumComponents, type, GL_FALSE, stride, offset);

	// Enables the generic VertexArrayAttrib pointed by index 
	glEnableVertexAttribArray(layout);

	// stop binding
	VBO_obj.unbind_VBO();
}

void VAO::bind_VAO()
{
	// binds the VAO with name "array" 
	glBindVertexArray(Profile_VAO);
}

void VAO::unbind_VAO()
{
	glBindVertexArray(0);
}

void VAO::Delete_VAO()
{
	glDeleteVertexArrays(1, &Profile_VAO);
}
