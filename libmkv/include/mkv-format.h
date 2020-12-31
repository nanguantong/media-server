#ifndef _mkv_format_h_
#define _mkv_format_h_

#ifdef __cplusplus
extern "C" {
#endif

#define MKV_MIME_AUDIO		"audio/x-matroska" // mka
#define MKV_MIME_VIDEO		"video/x-matroska" // mkv
#define MKV_MIME_VIDEO_3D	"video/x-matroska-3d"

// https://www.matroska.org/technical/codec_specs.html
enum mkv_codec_t
{
	MKV_CODEC_UNKNOWN = 0,

	MKV_CODEC_VIDEO_VCM,			// Microsoft (TM) Video Codec Manager (VCM)
	MKV_CODEC_VIDEO_UNCOMPRESSED,	// Video, raw uncompressed video frames
	MKV_CODEC_VIDEO_DIVX4,			// MPEG4 ISO simple profile (DivX4)
	MKV_CODEC_VIDEO_DIVX5,			// MPEG4 ISO advanced simple profile (DivX5, XviD, FFMPEG)
	MKV_CODEC_VIDEO_MPEG4,			// MPEG4 ISO advanced profile
	MKV_CODEC_VIDEO_MPEG4_MSV3,		// Microsoft (TM) MPEG4 V3
	MKV_CODEC_VIDEO_MPEG1,			// MPEG 1 Elementary Stream (ES)
	MKV_CODEC_VIDEO_MPEG2,			// MPEG 2 Elementary Stream (ES)
	MKV_CODEC_VIDEO_H264,			// AVC/H.264
	MKV_CODEC_VIDEO_H265,			// HEVC/H.265
	MKV_CODEC_VIDEO_RV10,			// RealVideo 1.0 aka RealVideo 5
	MKV_CODEC_VIDEO_RV20,			// RealVideo G2 and RealVideo G2+SVT
	MKV_CODEC_VIDEO_RV30,			// RealVideo 8
	MKV_CODEC_VIDEO_RV40,			// RealVideo 9
	MKV_CODEC_VIDEO_QUICKTIME,		// Video taken from QuickTime(TM) files
	MKV_CODEC_VIDEO_THEORA,			// Theora
	MKV_CODEC_VIDEO_PRORES,			// Apple ProRes
	MKV_CODEC_VIDEO_VP8,			// VP8 Codec format
	MKV_CODEC_VIDEO_VP9,			// VP9 Codec format
	MKV_CODEC_VIDEO_FFV1,			// FF Video Codec 1
	MKV_CODEC_VIDEO_AV1,			// AV1 Codec format
	MKV_CODEC_VIDEO_DIRAC,			// ffmpeg
	MKV_CODEC_VIDEO_MJPEG,			// ffmpeg

	MKV_CODEC_AUDIO_MP3 = 0x1000,	// MPEG Audio 1, 2, 2.5 Layer III
	MKV_CODEC_AUDIO_MP2,			// MPEG Audio 1, 2 Layer II
	MKV_CODEC_AUDIO_MP1,			// MPEG Audio 1, 2 Layer I
	MKV_CODEC_AUDIO_PCM_BE,			// PCM Integer Big Endian
	MKV_CODEC_AUDIO_PCM_LE,			// PCM Integer Little Endian
	MKV_CODEC_AUDIO_PCM_FLOAT,		// Floating Point, IEEE compatible(32/64 bits)
	MKV_CODEC_AUDIO_MPC,			// MPC (musepack) SV8
	MKV_CODEC_AUDIO_AC3,			// (Dolby) AC3
	MKV_CODEC_AUDIO_ALAC,			// ALAC (Apple Lossless Audio Codec)
	MKV_CODEC_AUDIO_DTS,			// Digital Theatre System
	MKV_CODEC_AUDIO_DTS_EXPRESS,	// Digital Theatre System Express
	MKV_CODEC_AUDIO_DTS_LOSSLESS,	// Digital Theatre System Lossless
	MKV_CODEC_AUDIO_VORBIS,			// Vorbis
	MKV_CODEC_AUDIO_FLAC,			// FLAC (Free Lossless Audio Codec)
	MKV_CODEC_AUDIO_RA1,			// Real Audio 1
	MKV_CODEC_AUDIO_RA2,			// Real Audio 2
	MKV_CODEC_AUDIO_COOK,			// Real Audio Cook Codec (codename: Gecko)
	MKV_CODEC_AUDIO_SIPR,			// Sipro Voice Codec
	MKV_CODEC_AUDIO_RALF,			// Real Audio Lossless Format
	MKV_CODEC_AUDIO_ATRC,			// Sony Atrac3 Codec
	MKV_CODEC_AUDIO_ACM,			// Microsoft(TM) Audio Codec Manager (ACM)
	MKV_CODEC_AUDIO_AAC,			// AAC MPEG2/MPEG4 MAIN/LC/SBR/SSR/LTP
	MKV_CODEC_AUDIO_QUICKTIME,		// Audio taken from QuickTime(TM) files
	MKV_CODEC_AUDIO_TTA1,			// The True Audio lossless audio compressor
	MKV_CODEC_AUDIO_WAVPACK4,		// WavPack lossless audio compressor
	MKV_CODEC_AUDIO_OPUS,			// Opus
	MKV_CODEC_AUDIO_TRUEHD,			// ffmpeg
	MKV_CODEC_AUDIO_EAC3,			// ffmpeg

	MKV_CODEC_SUBTITLE_TEXT = 0x2000,// UTF-8 Plain Text
	MKV_CODEC_SUBTITLE_SSA,			// Subtitles Format
	MKV_CODEC_SUBTITLE_ASS,			// Advanced Subtitles Format
	MKV_CODEC_SUBTITLE_USF,			// Universal Subtitle Format
	MKV_CODEC_SUBTITLE_WEBVTT,		// Web Video Text Tracks Format (WebVTT)
	MKV_CODEC_SUBTITLE_BMP,			// Bitmap
	MKV_CODEC_SUBTITLE_DVBSUB,		// Digital Video Broadcasting (DVB) subtitles
	MKV_CODEC_SUBTITLE_VOBSUB,		// VobSub subtitles
	MKV_CODEC_SUBTITLE_PGS,			// HDMV presentation graphics subtitles (PGS)
	MKV_CODEC_SUBTITLE_TEXTST,		// HDMV text subtitles
	MKV_CODEC_SUBTITLE_KATE,		// Karaoke And Text Encapsulation
};

enum
{
	MKV_FLAGS_KEYFRAME		= 0x00001, // Keyframe
	MKV_FLAGS_INVISIBLE		= 0x00002, // Invisible, the codec SHOULD decode this frame but not display it
	MKV_FLAGS_DISCARDABLE	= 0x00004, // Discardable, the frames of the Block can be discarded during playing if needed
};

enum ebml_video_interlaced_e
{
	EBML_VIDEO_FLAG_UNDETERMINED = 0,
	EBML_VIDEO_FLAG_INTERLACED = 1,
	EBML_VIDEO_FLAG_PROGRESSIVE = 2,
};

enum ebml_video_field_order_e
{
	EBML_VIDEO_FIELD_ORDER_PROGRESSIVE = 0,
	EBML_VIDEO_FIELD_ORDER_TTF = 1,
	EBML_VIDEO_FIELD_ORDER_UNDETERMINED = 2,
	EBML_VIDEO_FIELD_ORDER_BFF = 6,
	EBML_VIDEO_FIELD_ORDER_BFF_SWAPPED = 9,
	EBML_VIDEO_FIELD_ORDER_TTF_SWAPPED = 14,
};

enum ebml_video_stereo_mode_e
{
	EBML_VIDEO_STEREO_MODE_MONO = 0,
	EBML_VIDEO_STEREO_MODE_SIDE_BY_SIDE_LEFT = 1, // left eye first
	EBML_VIDEO_STEREO_MODE_TOP_BOTTOM_RIGHT = 2, // right eye first
	EBML_VIDEO_STEREO_MODE_TOP_BOTTOM_LEFT = 3, // left eye first
	EBML_VIDEO_STEREO_MODE_CHECKBOARD_RIGHT = 4, // right eye first
	EBML_VIDEO_STEREO_MODE_CHECKBOARD_LEFT = 5, // left eye first
	EBML_VIDEO_STEREO_MODE_ROW_INTERLEAVED_RIGHT = 6, // right eye first
	EBML_VIDEO_STEREO_MODE_ROW_INTERLEAVED_LEFT = 7, // left eye first
	EBML_VIDEO_STEREO_MODE_COLUMN_INTERLEAVED_RIGHT = 8, // right eye first
	EBML_VIDEO_STEREO_MODE_COLUMN_INTERLEAVED_LEFT = 9, // left eye first
	EBML_VIDEO_STEREO_MODE_ANAGLYPH_CYAN_RED = 10, // cyan/red
	EBML_VIDEO_STEREO_MODE_SIDE_BY_SIDE_RIGHT = 11, // right eye first
	EBML_VIDEO_STEREO_MODE_ANAGLYPH_GREEN_MAGENTA = 12, // green/megenta
	EBML_VIDEO_STEREO_MODE_BOTH_EYES_LACED_IN_ONE_BLOCK_LEFT = 13, // left eye first
	EBML_VIDEO_STEREO_MODE_BOTH_EYES_LACED_IN_ONE_BLOCK_RIGHT = 14, // right eye first
};

enum ebml_video_display_unit_e
{
	EBML_VIDEO_DISPLAY_UNIT_PIXELS = 0,
	EBML_VIDEO_DISPLAY_UNIT_CETIMETERS = 1,
	EBML_VIDEO_DISPLAY_UNIT_INCHES = 2,
	EBML_VIDEO_DISPLAY_UNIT_ASPECT_RATION = 3,
	EBML_VIDEO_DISPLAY_UNIT_UNKNOWN = 4,
};

enum ebml_video_aspect_ratio_type_e
{
	EBML_VIDEO_ASPECT_RATIO_TYPE_FREE_RESIZING = 0,
	EBML_VIDEO_ASPECT_RATIO_TYPE_KEEP_ASPECT_RATIOn = 1,
	EBML_VIDEO_ASPECT_RATIO_TYPE_FIXED = 2,
};

enum ebml_video_color_matrix_coefficients_t
{
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_IDENTIY = 0,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_ITU_R_BT709 = 1,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_UNSPECIFIED = 2,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_RESERVED = 3,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_US_FCC_73_682 = 4,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_ITU_R_BT_470BG = 5,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_SMPTE_170M = 6,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_SMPTE_240M = 7,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_YCOCG = 8,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_BT2020_NON_CONSTANT_LUMINANCE = 9,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_BT2020_CONSTANT_LUMINANCE = 10,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_SMPTE_ST_2085 = 11,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_CHROMA_DERIVED_NON_CONSTANT_LUMINANCE = 12,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_CHROMA_DERIVED_CONSTANT_LUMINANCE = 13,
	EBML_VIDEO_COLOR_MATRIX_COEFFICIENTS_ITU_R_BT_2100_0 = 14,
};

enum ebml_video_color_range_e
{
	EBML_VIDEO_COLOR_RANGE_UNSPECIFIED = 0,
	EBML_VIDEO_COLOR_RNAGE_BROADCAST_RANGE,
	EBML_VIDEO_COLOR_RNAGE_FULL_RANGE,
	EBML_VIDEO_COLOR_RNAGE_MATRIX_COEFFICIENTS,
};

enum ebml_video_color_transfer_characteristics_e
{
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_RESERVED = 0,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_ITU_R_BT_709 = 1,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_UNSPECIFIED = 2,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_GAMMA_2_2_CURVE_BT_470M = 4,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_GAMMA_2_8_CURVE_BT_470BG = 5,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_SMPTE_170M = 6,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_SMPTE_240M = 7,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_LINEAR = 8,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_LOG = 9,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_LOG_SQRT = 10,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_IEC_61966_2_4 = 11,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_ITU_R_BT_1361_EXTENDED_COLOUR_GAMUT = 12,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_IEC_61966_2_1 = 13,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_ITU_R_BT_2020_10BIT = 14,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_ITU_R_BT_2020_12BIT = 15,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_ITU_R_BT_2100_PERCEPTUAL_QUANTIZATION = 16,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_SMPTE_ST_428_1 = 17,
	EBML_VIDEO_COLOR_TRANSFER_CHARACTERISTICS_ARIB_STD_B67_HLG = 18,
};

enum ebml_video_color_primaries_e
{
	EBML_VIDEO_COLOR_PRIMARIES_RESERVED = 0,
	EBML_VIDEO_COLOR_PRIMARIES_ITU_R_BT_709 = 1,
	EBML_VIDEO_COLOR_PRIMARIES_UNSPECIFIED = 2,
	EBML_VIDEO_COLOR_PRIMARIES_ITU_R_BT_470M = 4,
	EBML_VIDEO_COLOR_PRIMARIES_ITU_R_BT_470BG_BT_601_625 = 5,
	EBML_VIDEO_COLOR_PRIMARIES_ITU_R_BT_601_525_TMPTE_170M = 6,
	EBML_VIDEO_COLOR_PRIMARIES_SMPTE_240M = 7,
	EBML_VIDEO_COLOR_PRIMARIES_FILM = 8,
	EBML_VIDEO_COLOR_PRIMARIES_ITU_R_BT_2020 = 9,
	EBML_VIDEO_COLOR_PRIMARIES_SMPTE_ST_428_1 = 10,
	EBML_VIDEO_COLOR_PRIMARIES_SMPTE_RP_432_2 = 11,
	EBML_VIDEO_COLOR_PRIMARIES_SMPTE_EG_432_2 = 12,
	EBML_VIDEO_COLOR_PRIMARIES_EBU_TECH_3212E_JEDEC_P22_PHOSPHORS = 22,
};

enum ebml_video_projection_type_e
{
	EBML_VIDEO_PROJECTION_RECTANGULAR = 0,
	EBML_VIDEO_PROJECTION_EQUIRECTANGULAR = 1,
	EBML_VIDEO_PROJECTION_CUBEMAP = 2,
	EBML_VIDEO_PROJECTION_MESH = 3,
};

#ifdef __cplusplus
}
#endif
#endif /* !_mkv_format_h_ */
