#pragma once

#include <stdexcept>
#include <string>
#include <vector>

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
    virtual void play_audio() = 0;
};

class IVideoPlayer {
public:
    virtual void display_video() = 0;
};

class IImagePlayer {
public:
    virtual void view_image() = 0;
};

class AudioPlayer : public IAudioPlayer {
public:
    void play_audio() final
    {
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

class ImagePlayer : public IImagePlayer {
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
        for (auto& media : media_list) {
            // Implementation...
        }
    }
};
