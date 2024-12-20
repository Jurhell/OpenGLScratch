#pragma once
#include <string>

class Renderer;

class Texture
{
private:
	//Declarations
	unsigned int m_rendererID;
	std::string m_filePath;
	unsigned char* m_localBuffer;
	int m_width, m_height, m_BPP; //Bits per pixel
public:
	Texture(const std::string& path);
	~Texture();

	//Binding and Unbinding
	void bind(unsigned int slot = 0) const;
	void unBind() const;

	//Getters
	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }
};