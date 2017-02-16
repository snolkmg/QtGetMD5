QString getMd5(const QString &filepath)
{
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    QCryptographicHash md5(QCryptographicHash::Md5);
    while(!file.atEnd())
    {
        md5.addData(file.read(8192));
    }
    QString Md5Str = md5.result().toHex().toUpper();
    file.close();
    return Md5Str;
}