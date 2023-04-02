object form_admin: Tform_admin
  Left = 0
  Top = 0
  Caption = #1042#1093#1086#1076
  ClientHeight = 142
  ClientWidth = 151
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object edit_admin: TEdit
    Left = 8
    Top = 61
    Width = 129
    Height = 21
    PasswordChar = '*'
    TabOrder = 0
    OnKeyPress = edit_adminKeyPress
  end
  object bt_admin: TButton
    Left = 32
    Top = 104
    Width = 75
    Height = 25
    Caption = #1054#1050
    TabOrder = 1
    OnClick = bt_adminClick
  end
  object StaticText1: TStaticText
    Left = 8
    Top = 8
    Width = 129
    Height = 47
    Alignment = taCenter
    AutoSize = False
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1087#1072#1088#1086#1083#1100' '#1076#1083#1103' '#1074#1093#1086#1076#1072' '#1074' '#1088#1077#1078#1080#1084#1077' '#1072#1076#1084#1080#1085#1080#1089#1090#1088#1072#1090#1086#1088#1072':'
    TabOrder = 2
  end
end
