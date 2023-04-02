object form_graphics: Tform_graphics
  Left = 0
  Top = 0
  Caption = #1043#1088#1072#1092#1080#1082#1080
  ClientHeight = 465
  ClientWidth = 563
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ChartGraphics: TChart
    Left = 0
    Top = 0
    Width = 408
    Height = 250
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082' '#1090#1086#1074#1072#1088#1086#1086#1073#1086#1088#1086#1090#1072)
    BottomAxis.Title.Caption = #1044#1072#1090#1072
    LeftAxis.Ticks.Width = 2
    LeftAxis.Title.Caption = #1042#1099#1088#1091#1095#1082#1072' ('#1088#1091#1073')'
    View3D = False
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      19
      15
      19)
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      ValueFormat = 'dd/MM/yyyy'
      XValues.DateTime = True
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
      Data = {0000000000}
    end
  end
  object ListBoxGraphics: TListBox
    Left = 414
    Top = 8
    Width = 145
    Height = 201
    ItemHeight = 13
    Sorted = True
    TabOrder = 1
    OnClick = ListBoxGraphicsClick
  end
  object bt_graphics: TButton
    Left = 448
    Top = 215
    Width = 75
    Height = 25
    Caption = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100
    TabOrder = 2
    OnClick = bt_graphicsClick
  end
  object ComboBoxGraphics: TComboBox
    Left = 414
    Top = 283
    Width = 145
    Height = 21
    Style = csDropDownList
    TabOrder = 3
    Items.Strings = (
      #1053#1077#1076#1077#1083#1103
      '2 '#1085#1077#1076#1077#1083#1080
      #1052#1077#1089#1103#1094
      '3 '#1084#1077#1089#1103#1094#1072
      '6 '#1084#1077#1089#1103#1094#1077#1074
      #1043#1086#1076
      '2 '#1075#1086#1076#1072
      '3 '#1075#1086#1076#1072
      '4 '#1075#1086#1076#1072
      '5 '#1083#1077#1090
      '10 '#1083#1077#1090)
  end
  object bt_sold_graphics: TButton
    Left = 448
    Top = 430
    Width = 75
    Height = 25
    Caption = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100
    TabOrder = 4
    OnClick = bt_sold_graphicsClick
  end
  object ChartSoldGraphics: TChart
    Left = 0
    Top = 248
    Width = 408
    Height = 218
    Title.Text.Strings = (
      #1057#1091#1084#1084#1072' '#1088#1077#1072#1083#1080#1079#1086#1074#1072#1085#1085#1086#1081' '#1087#1088#1086#1076#1091#1082#1094#1080#1080' '#1079#1072' '#1087#1077#1088#1080#1086#1076)
    BottomAxis.Labels = False
    BottomAxis.LabelsFormat.Visible = False
    BottomAxis.Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1077#1076#1080#1085#1080#1094#1099
    LeftAxis.Title.Caption = #1057#1091#1084#1084#1072#1088#1085#1072#1103' '#1074#1099#1088#1091#1095#1082#1072' ('#1088#1091#1073')'
    View3D = False
    TabOrder = 5
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      23
      15
      23)
    ColorPaletteIndex = 13
    object Series2: TBarSeries
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
      Data = {0000000000}
      Detail = {0000000000}
    end
  end
  object ChartDataSet1: TChartDataSet
    Chart = ChartGraphics
    Left = 528
    Top = 352
  end
end
