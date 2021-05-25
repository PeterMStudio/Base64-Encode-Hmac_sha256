#include "hmac.h"

int main(){
   
    /* equal ph
    $s = hash_hmac('sha256',
    'hello world',
    'writer',
    true);
    echo $s;
    echo base64_encode($s)
    ?>
    */
    
    HMac::base64Encode(HMac::cHMacSha256("hello world", "writer",true),true);
}
