/**
 * Copyright 2011-2013 - Reliable Bits Software by Blommers IT. All Rights Reserved.
 * Author Rick Blommers
 */

#pragma once

#include "edbee/models/textchange.h"

namespace edbee {

class TextDocSelState;
class TextEditorController;
class TextRangeSet;

/// Move the caret / and selection commands
class SelectionTextChange: public ControllerTextChange
{
public:

    SelectionTextChange( TextEditorController* controller );
    virtual ~SelectionTextChange();

    virtual void giveTextRangeSet( TextRangeSet* rangeSet );

    virtual void execute(TextDocument* document);
    virtual void revert(TextDocument* document);

    virtual bool merge(TextDocument *document, TextChange* textChange );
    TextRangeSet* rangeSet() { return rangeSet_; }

    virtual QString toString();

protected:
    void notifyChange();

private:

    TextRangeSet* rangeSet_;            ///< This rangeset contains the new ranges OR the old ranges, depending on the state on the undo-stack (This is scary but saves us the storage of a compelte rangeSet)
};


} // edbee
