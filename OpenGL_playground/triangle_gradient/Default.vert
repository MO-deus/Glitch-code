		#version 330 core
		layout (location = 0) in vec3 aPos;		// allocates the storage for the defined variable
		layout (location = 1) in vec3 aColor;	// allocates the storage for the colors to be stored

		out vec3 color;

		uniform float scale_multiplier;

		void main()
		{
			gl_Position = vec4(aPos.x + aPos.x * scale_multiplier, aPos.y + aPos.y * scale_multiplier , aPos.z + aPos.z * scale_multiplier, 1.0);
			color = aColor;
		}