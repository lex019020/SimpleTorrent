#include "utils.h"

Utils::Utils()
{

}

QString Utils::get_size_string(size_t bytes)
{
    auto size_tmp = bytes;
    QString prefix = "";

    if(bytes >= pow(2, 30))
    {
        prefix = "Gi";
        size_tmp /= pow(2, 30);
    }
    else if(bytes >= pow(2, 20)){
        prefix = "Mi";
        size_tmp /= pow(2, 20);
    }
    else if(bytes >= pow(2, 10)){
        prefix = "Ki";
        size_tmp /= pow(2, 10);
    }

    return QString("%1 %2B").arg(size_tmp).arg(prefix);
}
