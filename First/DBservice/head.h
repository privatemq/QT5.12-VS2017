#pragma once

#ifndef BIL_H        
#define BIL_H  
// ����BIL_SHARE��ʹ���߿��Բ����ٴ�����ŵĵ���͵���ϸ��        
#ifdef BIL_LIB        
# define BIL_SHARE  Q_DECL_EXPORT        
#else        
# define BIL_SHARE  Q_DECL_IMPORT        
#endif 

#endif // BIL_H   
