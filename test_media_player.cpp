#include <gmock/gmock.h>

#include "media_player.h"

TEST(AudioPlayerTest, PlayAudio)
{
    AudioPlayer audio_player;
    ASSERT_NO_THROW(audio_player.play_audio());
    ASSERT_THROW(audio_player.display_video(), std::logic_error);
    ASSERT_THROW(audio_player.view_image(), std::logic_error);
}

TEST(VideoPlayerTest, DisplayVideo)
{
    VideoPlayer videoPlayer;
    ASSERT_NO_THROW(videoPlayer.display_video());
    ASSERT_THROW(videoPlayer.play_audio(), std::logic_error);
    ASSERT_THROW(videoPlayer.view_image(), std::logic_error);
}

TEST(ImagePlayerTest, ViewImage)
{
    ImagePlayer imagePlayer;
    ASSERT_NO_THROW(imagePlayer.view_image());
    ASSERT_THROW(imagePlayer.play_audio(), std::logic_error);
    ASSERT_THROW(imagePlayer.display_video(), std::logic_error);
}
