.segment "CHR"
    .incbin "chr_bank0.chr"
    .incbin "chr_bank1.chr"
    .incbin "chr_bank2.chr"
    .incbin "chr_bank3.chr"

.segment "DATA_BANK_2"
_test_map:
    .export _test_map
    .incbin "nametable_0.nam"

.segment "SAMPLE_BANK_3"
_music_data:
    .export _music_data
    .incbin "garazh.dmc"
