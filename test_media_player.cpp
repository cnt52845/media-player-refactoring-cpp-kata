#include <gmock/gmock.h>

#include "media_player.h"

TEST(AudioPlayerTest, PlayAudio)
{
    AudioPlayer audio_player;
    EXPECT_NO_THROW(audio_player.play_audio());
    EXPECT_THROW(audio_player.display_video(), std::logic_error);
    EXPECT_THROW(audio_player.view_image(), std::logic_error);
}

TEST(VideoPlayerTest, DisplayVideo)
{
    VideoPlayer videoPlayer;
    EXPECT_NO_THROW(videoPlayer.display_video());
    EXPECT_THROW(videoPlayer.play_audio(), std::logic_error);
    EXPECT_THROW(videoPlayer.view_image(), std::logic_error);
}

TEST(ImagePlayerTest, ViewImage)
{
    ImagePlayer imagePlayer;
    EXPECT_NO_THROW(imagePlayer.view_image());
    EXPECT_THROW(imagePlayer.play_audio(), std::logic_error);
    EXPECT_THROW(imagePlayer.display_video(), std::logic_error);
}

TEST(MediaListPlayerTest, MediaListPlayerPlaysCompatibleList)
{
    std::vector<MediaFile> media_list{/* populate media files */};
    Players                players{/* populate players */};

    MediaListPlayer list_player;
    EXPECT_NO_THROW(list_player.play_list(media_list, players));
}
