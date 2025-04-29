#include <gmock/gmock.h>

#include "media_player.h"

TEST(AudioPlayerTest, PlayAudio)
{
    AudioPlayer audio_player;
    EXPECT_NO_THROW(audio_player.play_audio());
}

TEST(VideoPlayerTest, DisplayVideo)
{
    VideoPlayer videoPlayer;
    EXPECT_NO_THROW(videoPlayer.display_video());
}

TEST(ImagePlayerTest, ViewImage)
{
    ImagePlayer imagePlayer;
    EXPECT_NO_THROW(imagePlayer.view_image());
}

TEST(MediaListPlayerTest, MediaListPlayerPlaysCompatibleList)
{
    std::vector<MediaFile> media_list{/* populate media files */};
    Players                players{/* populate players */};

    MediaListPlayer list_player;
    EXPECT_NO_THROW(list_player.play_list(media_list, players));
}
