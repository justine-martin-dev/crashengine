#include "CrashEngine/default-handlers/opengl/OpenGlTexture.hpp"

namespace crashengine {

    OpenGlTexture::OpenGlTexture(const std::string& path, TextureSettings textureSettings)
        : Texture(textureSettings)
    {

        glGenTextures(1, &this->id);

        this->bindToSlot(0);

        GLint                 openglTextureWrapping[]    = { GL_REPEAT, GL_MIRRORED_REPEAT, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER };
        constexpr std::size_t openglTextureWrappingCount = 4;

        GLint                 openglTextureFiltering[]    = { GL_NEAREST, GL_LINEAR };
        constexpr std::size_t openglTextureFilteringCount = 2;

        if (textureSettings.textureWrapping >= openglTextureWrappingCount) {
            log::compatibilityWarning("OpenGL doesn't know how to handle the texture wrapping with value of " + std::to_string(textureSettings.textureWrapping) + ". The value will be set back to REPEAT.");

            textureSettings.textureWrapping = TextureWrapping::REPEAT;
        }

        if (textureSettings.textureFiltering >= openglTextureFilteringCount) {
            log::compatibilityWarning("OpenGL doesn't know how to handle the texture filtering with value of " + std::to_string(textureSettings.textureWrapping) + ". The value will be set back to LINEAR.");

            textureSettings.textureFiltering = Filtering::LINEAR;
        }

        if (textureSettings.mipMapFiltering >= openglTextureFilteringCount) {
            log::compatibilityWarning("OpenGL doesn't know how to handle the mipmap filtering with value of " + std::to_string(textureSettings.textureWrapping) + ". The value will be set back to LINEAR.");

            textureSettings.mipMapFiltering = Filtering::LINEAR;
        }

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, openglTextureWrapping[textureSettings.textureWrapping]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, openglTextureWrapping[textureSettings.textureWrapping]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, openglTextureFiltering[textureSettings.textureFiltering]);
        if (textureSettings.shouldGenerateMipmap) {
            switch (textureSettings.textureFiltering) {
            case Filtering::LINEAR:
                switch (textureSettings.mipMapFiltering) {
                case Filtering::LINEAR:
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                    break;

                case Filtering::NEAREST:
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
                    break;

                default:
                    log::compatibilityWarning("Can't generate a texture filter with textureFiltering at " + std::to_string(textureSettings.textureFiltering) + " and mipmapFiltering at " + std::to_string(textureSettings.mipMapFiltering));
                }
                break;

            case Filtering::NEAREST:
                switch (textureSettings.textureFiltering) {
                case Filtering::LINEAR:
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
                    break;

                case Filtering::NEAREST:
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
                    break;

                default:
                    log::error("Can't generate a texture filter with textureFiltering at " + std::to_string(textureSettings.textureFiltering) + " and mipmapFiltering at " + std::to_string(textureSettings.mipMapFiltering));
                }
                break;

            default:
                log::error("Can't generate a texture filter with textureFiltering at " + std::to_string(textureSettings.textureFiltering) + " and mipmapFiltering at " + std::to_string(textureSettings.mipMapFiltering));
            }
        } else {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, openglTextureFiltering[textureSettings.textureFiltering]);
        }

        if (textureSettings.textureWrapping == TextureWrapping::CLAMP_TO_BORDER) {
            float borderColor[] = { 0.0f, 0.0f, 0.0f, 1.0f };
            glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
        }

        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);

        unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        if (textureSettings.shouldGenerateMipmap) {
            glGenerateMipmap(GL_TEXTURE_2D);
        }

        stbi_image_free(data);
    }

    void OpenGlTexture::bindToSlot(std::size_t textureSlot)
    {
        glActiveTexture(GL_TEXTURE0 + textureSlot);
        glBindTexture(GL_TEXTURE_2D, this->id);
    }

    void OpenGlTexture::unbind(std::size_t texture_slot)
    {
        glActiveTexture(GL_TEXTURE0 + texture_slot);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}
