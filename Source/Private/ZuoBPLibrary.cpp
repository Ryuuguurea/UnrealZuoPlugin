#include "ZuoBPLibrary.h"
#include "zuo.hpp"
FString UZuoBPLibrary::ZuoEval(const FString& code){
    
    const auto prog = StringCast<UTF8CHAR>(*code);
    zuo_ext_t *ht, *dynamic_require, *main, *v;


    /* Run `prog`: */
    ht = zuo_ext_eval_module(zuo_ext_symbol("main-app"), (const char*)prog.Get(), strlen((const char*)prog.Get()));

    dynamic_require = zuo_ext_hash_ref(ht,
                                        zuo_ext_symbol("dynamic-require"),
                                        zuo_ext_false());

    main = zuo_ext_apply(dynamic_require,
                        zuo_ext_cons(zuo_ext_symbol("main-app"),
                                        zuo_ext_cons(zuo_ext_symbol("main"),
                                                    zuo_ext_null())));

    v = zuo_ext_apply(main, zuo_ext_null());

    char* ret = zuo_ext_string_ptr(zuo_ext_apply(zuo_ext_hash_ref(zuo_ext_kernel_env(),
                                                            zuo_ext_symbol("~s"),
                                                            zuo_ext_false()),
                                            zuo_ext_cons(v, zuo_ext_null())));
    return UTF8_TO_TCHAR(ret);
}