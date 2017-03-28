//
// Created by agnieszka on 28.03.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace memorychunk
{
    class MemoryChunk
    {
    public:
        MemoryChunk(size_t sz);
        MemoryChunk(const MemoryChunk &m);
        MemoryChunk(MemoryChunk &&m);
        MemoryChunk &operator=(const MemoryChunk &m);
        MemoryChunk &operator=(MemoryChunk &&m);
        ~MemoryChunk();
        int8_t *MemoryAt(size_t offset) const;
        size_t ChunkSize() const;

    private:
        int8_t *ptr;
        size_t sz;
    };


}
#endif //JIMP_EXERCISES_MEMORYCHUNK_H
