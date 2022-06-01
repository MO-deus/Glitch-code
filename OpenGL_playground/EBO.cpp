
#include "EBO.h"

EBO::EBO(GLuint* indices, GLsizeiptr size_EBO)
{
	// generate Vertexbuffer 
	glGenBuffers(1, &Profile_EBO);

	// Binds the name buffer to object buffer , helps in rendering,
	// specifying the type of EBO (GL_ARRAY_ELEMENT_BUFFER)
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Profile_EBO);

	// storing indices in buffer 
	// GL_STATIC_DRAW : verices will be modified once and used many times and draw an img on screen
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_EBO, indices, GL_STATIC_DRAW);
}

void EBO::bind_EBO()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Profile_EBO);
}

void EBO::unbind_EBO()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete_EBO()
{
	glDeleteBuffers(1, &Profile_EBO);
}
