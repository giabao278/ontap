Imports System.IO.Ports

Public Class Form1
    Dim minVal As Integer
    Dim maxVal As Integer

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        SerialPort1.PortName = "COM18"
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        SerialPort1.Open()
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        maxVal = Val(TextBox1.Text)
        If maxVal < Val(TextBox2.Text) Then
            maxVal = Val(TextBox2.Text)
        End If
        If maxVal < Val(TextBox3.Text) Then
            maxVal = Val(TextBox3.Text)
        End If
        'TextBox4.Text = Str(maxVal)
        SerialPort1.Write(New Byte() {Convert.ToByte(maxVal) + &H_30}, 0, 1)
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        minVal = Val(TextBox1.Text)
        If minVal > Val(TextBox2.Text) Then
            minVal = Val(TextBox2.Text)
        End If
        If minVal > Val(TextBox3.Text) Then
            minVal = Val(TextBox3.Text)
        End If
        'TextBox5.Text = Str(minVal)
        SerialPort1.Write(New Byte() {Convert.ToByte(minVal) + &H_30}, 0, 1)
    End Sub

    '---------------------------------'
    Private Delegate Sub SerialDelegate(ByVal Buffer As String)
    Private adre As New SerialDelegate(AddressOf DisplayData)

    Private Sub SerialPort1_DataReceived(sender As Object, e As SerialDataReceivedEventArgs) Handles SerialPort1.DataReceived
        Dim sRevc As String = SerialPort1.ReadExisting()
        Me.Invoke(adre, sRevc)
    End Sub

    Private Sub DisplayData(ByVal sdata As String)
        If sdata = "a" Then
            TextBox4.Text = Str(Val(TextBox1.Text) + Val(TextBox2.Text) + Val(TextBox3.Text))
        ElseIf sdata = "b" Then
            TextBox5.Text = Str(Val(TextBox1.Text) * Val(TextBox2.Text) * Val(TextBox3.Text))
        End If
    End Sub
End Class
