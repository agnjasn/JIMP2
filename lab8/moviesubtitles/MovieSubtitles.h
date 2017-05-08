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
        NegativeFrameAfterShift()
        {
        }
        ~NegativeFrameAfterShift() {}

    };

    class SubtitleEndBeforeStart
    {
    public:
        SubtitleEndBeforeStart(int a)
        {
            wrong_line_=a;
        }
        ~SubtitleEndBeforeStart() {}
        int LineAt() const {
            return wrong_line_;
        }

        std::string what() const
        {
            return "At line "+std::to_string(wrong_line_)+": {260}{220}NEWLINE";
        }

    private:
        int wrong_line_;

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

    class MissingTimeSpecification
    {
        public:
        MissingTimeSpecification(){};
    };

    class OutOfOrderFrames
    {
    public:
        OutOfOrderFrames(){};
    };

}



#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
