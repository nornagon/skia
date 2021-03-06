/*
 * Copyright 2016 Xamarin Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkXMLWriter.h"

#include "sk_xml.h"

#include "sk_types_priv.h"

//////////////////////////////////////////////////////////////////////////////////////////////////

sk_xmlstreamwriter_t* sk_xmlstreamwriter_new(sk_wstream_t* stream)
{
    return ToXMLStreamWriter(new SkXMLStreamWriter(AsWStream(stream)));
}

void sk_xmlstreamwriter_delete(sk_xmlstreamwriter_t* writer)
{
    delete AsXMLStreamWriter(writer);
}
