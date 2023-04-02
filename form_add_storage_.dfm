object form_add_storage: Tform_add_storage
  Left = 0
  Top = 0
  Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1101#1083#1077#1084#1077#1085#1090
  ClientHeight = 231
  ClientWidth = 277
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object edit_add_storage_name: TEdit
    Left = 136
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object edit_add_storage_type: TEdit
    Left = 136
    Top = 43
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object edit_add_storage_condition: TEdit
    Left = 136
    Top = 70
    Width = 121
    Height = 21
    AutoSize = False
    TabOrder = 2
  end
  object edit_add_storage_date: TEdit
    Left = 136
    Top = 97
    Width = 121
    Height = 21
    TabOrder = 3
    OnKeyPress = edit_add_storage_dateKeyPress
  end
  object edit_add_storage_count: TEdit
    Left = 136
    Top = 151
    Width = 121
    Height = 21
    TabOrder = 4
    OnKeyPress = edit_add_storage_countKeyPress
  end
  object edit_add_storage_price: TEdit
    Left = 136
    Top = 124
    Width = 121
    Height = 21
    TabOrder = 5
    OnKeyPress = edit_add_storage_priceKeyPress
  end
  object text_add_storage_name: TStaticText
    Left = 27
    Top = 16
    Width = 81
    Height = 17
    Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077':'
    TabOrder = 6
  end
  object text_add_storage_type: TStaticText
    Left = 76
    Top = 43
    Width = 26
    Height = 17
    Caption = #1058#1080#1087':'
    TabOrder = 7
  end
  object text_add_storage_condition: TStaticText
    Left = 46
    Top = 70
    Width = 62
    Height = 17
    Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077':'
    TabOrder = 8
  end
  object text_add_storage_date: TStaticText
    Left = 17
    Top = 97
    Width = 91
    Height = 17
    Caption = #1044#1072#1090#1072' '#1087#1086#1083#1091#1095#1077#1085#1080#1103':'
    TabOrder = 9
  end
  object text_add_storage_price: TStaticText
    Left = 46
    Top = 124
    Width = 62
    Height = 17
    Caption = #1057#1090#1086#1080#1084#1086#1089#1090#1100':'
    TabOrder = 10
  end
  object text_add_storage_count: TStaticText
    Left = 40
    Top = 151
    Width = 68
    Height = 17
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
    TabOrder = 11
  end
  object bt_ok_storage: TButton
    Left = 182
    Top = 205
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 12
    OnClick = bt_ok_storageClick
  end
  object bt_cancel_storage: TButton
    Left = 33
    Top = 205
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 13
    OnClick = bt_cancel_storageClick
  end
  object edit_add_storage_date2: TEdit
    Left = 136
    Top = 178
    Width = 121
    Height = 21
    TabOrder = 14
    Visible = False
  end
  object text_add_storage_date2: TStaticText
    Left = 29
    Top = 178
    Width = 79
    Height = 17
    Caption = #1044#1072#1090#1072' '#1086#1090#1075#1088#1091#1079#1082#1080
    TabOrder = 15
    Visible = False
  end
end
