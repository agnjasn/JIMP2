//
// Created by KInga on 06.05.2017.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <sstream>
namespace moviesubs
{

    class MovieSubtitles
    {
    public:
        ~MovieSubtitles(){}
       virtual void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream* in, std::stringstream* out)=0;

    };

    class MicroDvdSubtitles : public MovieSubtitles
    {
    public:
        ~MicroDvdSubtitles(){}
        MicroDvdSubtitles();
        void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream* in, std::stringstream* out) override ;

    };

    class NegativeFrameAfterShift
    {
    public:
        ~NegativeFrameAfterShift() {}

    };

    class SubtitleEndBeforeStart
    {
    public:
        ~SubtitleEndBeforeStart() {}

    };

    class InvalidSubtitleLineFormat
    {
    public:
        ~InvalidSubtitleLineFormat(){}

    };

    class SubRipSubtitles : public  MovieSubtitles
    {
    public:
        ~SubRipSubtitles(){}
        void ShiftAllSubtitlesBy(int delay, int fps, std::stringstream* in, std::stringstream* out) override ;

    };

}



#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
