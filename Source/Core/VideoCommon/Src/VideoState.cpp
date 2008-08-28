// Copyright (C) 2003-2008 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#include "VideoState.h"

#include "BPMemory.h"
#include "CPMemory.h"
#include "XFMemory.h"
#include "TextureDecoder.h"
#include "Fifo.h"

static void DoState(ChunkFile &f) {
    // BP Memory
    f.Do(bpmem);
    // CP Memory
    f.Do(arraybases);
    f.Do(arraystrides);
    f.Do(MatrixIndexA);
    f.Do(MatrixIndexB);
    // XF Memory
    f.Do(xfregs);
	PanicAlert("video: XFMem");
    f.Do(xfmem);
	PanicAlert("video: Texture decoder");
    // Texture decoder
    f.Do(texMem);
 
    // FIFO
	PanicAlert("video: FIFO");
    Fifo_DoState(f);

    //TODO: Check for more pointers in the data structures and make them
    //      serializable
}

void VideoCommon_DoState(ChunkFile &f) {
    PanicAlert("Saving state from Video Common Library");
    //TODO: Save the video state
    f.Descend("VID ");
    DoState(f);
    f.Ascend();
	PanicAlert("END save video");
}
