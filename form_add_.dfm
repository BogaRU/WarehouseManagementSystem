object form_add: Tform_add
  Left = 0
  Top = 0
  Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1086#1090#1088#1091#1076#1085#1080#1082#1072
  ClientHeight = 138
  ClientWidth = 242
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object edit_add_name: TEdit
    Left = 114
    Top = 8
    Width = 120
    Height = 21
    TabOrder = 0
    OnKeyPress = edit_add_nameKeyPress
  end
  object edit_add_pas: TEdit
    Left = 114
    Top = 35
    Width = 120
    Height = 21
    PasswordChar = '*'
    TabOrder = 1
    OnKeyPress = edit_add_pasKeyPress
  end
  object edit_add_repeat: TEdit
    Left = 114
    Top = 62
    Width = 120
    Height = 21
    PasswordChar = '*'
    TabOrder = 2
    OnKeyPress = edit_add_repeatKeyPress
  end
  object bt_add_ok: TButton
    Left = 160
    Top = 106
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 3
    OnClick = bt_add_okClick
  end
  object bt_add_cancel: TButton
    Left = 7
    Top = 105
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 4
    OnClick = bt_add_cancelClick
  end
  object text_add_name: TStaticText
    Left = 43
    Top = 8
    Width = 39
    Height = 21
    Caption = #1048#1084#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object text_add_pas: TStaticText
    Left = 18
    Top = 35
    Width = 64
    Height = 21
    Caption = #1055#1072#1088#1086#1083#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object text_add_repeat: TStaticText
    Left = 18
    Top = 60
    Width = 64
    Height = 23
    Caption = #1055#1072#1088#1086#1083#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
end
