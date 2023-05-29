#pragma once

#include <stdexcept>
class IMediaPlayer {
public:
    virtual void play_audio()    = 0;
    virtual void display_video() = 0;
    virtual void view_image()    = 0;
};

class AudioPlayer : public IMediaPlayer {
public:
    void play_audio() final
    {
        // Implementation...
    }
    void display_video() final { throw std::logic_error("Not implemented"); }
    void view_image() final { throw std::logic_error("Not implemented"); }
};

class VideoPlayer : public IMediaPlayer {
public:
    void play_audio() final { throw std::logic_error("Not implemented"); }
    void display_video() final
    {
        // Implementation...
    }
    void view_image() final { throw std::logic_error("Not implemented"); }
};

class ImagePlayer : public IMediaPlayer {
public:
    void play_audio() final { throw std::logic_error("Not implemented"); }
    void display_video() final { throw std::logic_error("Not implemented"); }
    void view_image() final
    {
        // Implementation...
    }
};
