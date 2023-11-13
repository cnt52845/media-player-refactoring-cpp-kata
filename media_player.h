#pragma once

#include <stdexcept>
#include <string>

class MediaFile {
public:
    std::string format;
    std::string filename;
};

class IMediaPlayer {
public:
    virtual void play_audio()    = 0;
    virtual void display_video() = 0;
    virtual void view_image()    = 0;
};

class IAudioPlayer {
public:
    virtual void play_audio(const MediaFile& file) = 0;
};

class IVideoPlayer {
public:
    virtual void display_video() = 0;
};

class IImageViewer {
public:
    virtual void view_image() = 0;
};

class Mp3Player : public IAudioPlayer {
public:
    void play_audio(const MediaFile& file) override
    {
        if (file.format != "mp3") {
            throw std::invalid_argument("Invalid file format for Mp3Player!");
        }
        // Implementation...
    }
};

class FlacPlayer : public IAudioPlayer {
public:
    void play_audio(const MediaFile& file) override
    {
        if (file.format != "flac") {
            throw std::invalid_argument("Invalid file format for FlacPlayer!");
        }
        // Implementation...
    }
};

class WavPlayer : public IAudioPlayer {
public:
    void play_audio(const MediaFile& file) override
    {
        if (file.format != "wav") {
            throw std::invalid_argument("Invalid file format for WavPlayer!");
        }
        // Implementation...
    }
};

class VideoPlayer : public IVideoPlayer {
public:
    void display_video() final
    {
        // Implementation...
    }
};

class ImagePlayer : public IImageViewer {
public:
    void view_image() final
    {
        // Implementation...
    }
};

using Players = std::vector<std::shared_ptr<IMediaPlayer>>;

class MediaListPlayer {
public:
    void play_list(const std::vector<MediaFile>& media_list, const Players& players)
    {
        for (size_t i = 0; i < media_list.size(); i++) {
            // Implementation...
        }
    }
};
