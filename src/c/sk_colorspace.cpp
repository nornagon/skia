/*
 * Copyright 2017 Xamarin Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkColorSpace.h"

#include "sk_colorspace.h"

#include "sk_types_priv.h"

void sk_colorspace_unref(sk_colorspace_t* cColorSpace) {
    SkSafeUnref(AsColorSpace(cColorSpace));
}

sk_colorspace_t* sk_colorspace_new_named(sk_colorspace_named_t named) {
    return ToColorSpace(SkColorSpace::MakeNamed((SkColorSpace::Named)named).release());
}

sk_colorspace_t* sk_colorspace_new_icc(const void* input, size_t len) {
    return ToColorSpace(SkColorSpace::MakeICC(input, len).release());
}

sk_colorspace_t* sk_colorspace_new_rgb_with_gamma(sk_colorspace_render_target_gamma_t gamma, const sk_matrix44_t* toXYZD50) {
    return ToColorSpace(SkColorSpace::MakeRGB((SkColorSpace::RenderTargetGamma)gamma, AsMatrix44(*toXYZD50)).release());
}

sk_colorspace_t* sk_colorspace_new_rgb_with_coeffs(const sk_colorspace_transfer_fn_t* coeffs, const sk_matrix44_t* toXYZD50) {
    return ToColorSpace(SkColorSpace::MakeRGB(AsColorSpaceTransferFn(*coeffs), AsMatrix44(*toXYZD50)).release());
}

bool sk_colorspace_gamma_close_to_srgb(const sk_colorspace_t* cColorSpace) {
    return AsColorSpace(cColorSpace)->gammaCloseToSRGB();
}

bool sk_colorspace_gamma_is_linear(const sk_colorspace_t* cColorSpace) {
    return AsColorSpace(cColorSpace)->gammaIsLinear();
}

bool sk_colorspace_equals(const sk_colorspace_t* src, const sk_colorspace_t* dst) {
    return SkColorSpace::Equals(AsColorSpace(src), AsColorSpace(dst));
}

bool sk_colorspaceprimaries_to_xyzd50(const sk_colorspaceprimaries_t* primaries, sk_matrix44_t* toXYZD50) {
    return AsColorSpacePrimaries(primaries)->toXYZD50(AsMatrix44(toXYZD50));
}
