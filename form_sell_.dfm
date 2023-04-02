object form_sell: Tform_sell
  Left = 0
  Top = 0
  Caption = #1054#1090#1075#1088#1091#1079#1082#1072' '#1087#1088#1086#1076#1091#1082#1094#1080#1080
  ClientHeight = 40
  ClientWidth = 169
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object edit_sell: TEdit
    Left = 8
    Top = 8
    Width = 75
    Height = 21
    TabOrder = 0
    Text = '0'
    OnKeyPress = edit_sellKeyPress
  end
  object UpDown1: TUpDown
    Left = 83
    Top = 8
    Width = 16
    Height = 21
    Associate = edit_sell
    Max = 10000000
    TabOrder = 1
  end
  object bt_sell_ok: TButton
    Left = 103
    Top = 8
    Width = 58
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = bt_sell_okClick
  end
end
