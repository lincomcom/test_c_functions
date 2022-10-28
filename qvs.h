#ifndef _HAD_QVS_H_
#define _HAD_QVS_H_

#if defined (__cplusplus)
extern "C" {
#endif

#include <stdbool.h>

enum {
    _QVS_NOTIFY_MIN = 0,
    _QVS_NOTIFY_OK = _QVS_NOTIFY_MIN,
    _QVS_NOTIFY_ERROR_UNKNOWN,
    _QVS_NOTIFY_ERROR_CONFIG,
    _QVS_NOTIFY_ERROR_NEGOTIATE,
    _QVS_NOTIFY_ERROR_MIGRATION,
    _QVS_NOTIFY_ERROR_HOST,
    _QVS_NOTIFY_ERROR_HAD,
    _QVS_NOTIFY_ERROR_LIBVIRTD,
    _QVS_NOTIFY_ERROR_PVM,
    _QVS_NOTIFY_ERROR_PVM_NORMAL_SHUTDOWN,
    _QVS_NOTIFY_ERROR_SVM,
    _QVS_NOTIFY_ERROR_SVM_NORMAL_SHUTDOWN,
    _QVS_NOTIFY_ERROR_ALINKS,
    _QVS_NOTIFY_ERROR_BLINKS,
    _QVS_NOTIFY_ERROR_MLINKS,
    _QVS_NOTIFY_ERROR_QUORUM_WITNESS,
    _QVS_NOTIFY_ERROR_GATEWAY,
    _QVS_NOTIFY_ERROR_WATCHDOG,
    _QVS_NOTIFY_MAX,
};

#define QVS_NOTIFY_OK                           (1 << _QVS_NOTIFY_OK)
#define QVS_NOTIFY_ERROR_UNKNOWN                (1 << _QVS_NOTIFY_ERROR_UNKNOWN)
#define QVS_NOTIFY_ERROR_CONFIG                 (1 << _QVS_NOTIFY_ERROR_CONFIG)
#define QVS_NOTIFY_ERROR_NEGOTIATE              (1 << _QVS_NOTIFY_ERROR_NEGOTIATE)
#define QVS_NOTIFY_ERROR_MIGRATION              (1 << _QVS_NOTIFY_ERROR_MIGRATION)
#define QVS_NOTIFY_ERROR_HOST                   (1 << _QVS_NOTIFY_ERROR_HOST)
#define QVS_NOTIFY_ERROR_HAD                    (1 << _QVS_NOTIFY_ERROR_HAD)
#define QVS_NOTIFY_ERROR_LIBVIRTD               (1 << _QVS_NOTIFY_ERROR_LIBVIRTD)
#define QVS_NOTIFY_ERROR_PVM                    (1 << _QVS_NOTIFY_ERROR_PVM)
#define QVS_NOTIFY_ERROR_PVM_NORMAL_SHUTDOWN    (1 << _QVS_NOTIFY_ERROR_PVM_NORMAL_SHUTDOWN)
#define QVS_NOTIFY_ERROR_SVM                    (1 << _QVS_NOTIFY_ERROR_SVM)
#define QVS_NOTIFY_ERROR_SVM_NORMAL_SHUTDOWN    (1 << _QVS_NOTIFY_ERROR_SVM_NORMAL_SHUTDOWN)
#define QVS_NOTIFY_ERROR_ALINKS                 (1 << _QVS_NOTIFY_ERROR_ALINKS)
#define QVS_NOTIFY_ERROR_BLINKS                 (1 << _QVS_NOTIFY_ERROR_BLINKS)
#define QVS_NOTIFY_ERROR_MLINKS                 (1 << _QVS_NOTIFY_ERROR_MLINKS)
#define QVS_NOTIFY_ERROR_QUORUM_WITNESS         (1 << _QVS_NOTIFY_ERROR_QUORUM_WITNESS)
#define QVS_NOTIFY_ERROR_GATEWAY                (1 << _QVS_NOTIFY_ERROR_GATEWAY)
#define QVS_NOTIFY_ERROR_WATCHDOG               (1 << _QVS_NOTIFY_ERROR_WATCHDOG)

enum {
    _HAD_QVS_NOTIFY_MIN = 0,
    _HAD_QVS_NOTIFY_ERROR_UNKNOWN = _HAD_QVS_NOTIFY_MIN,
    _HAD_QVS_NOTIFY_ERROR_ALINKS,
    _HAD_QVS_NOTIFY_ERROR_MLINKS,
    _HAD_QVS_NOTIFY_ERROR_BLINKS,
    _HAD_QVS_NOTIFY_RETRY,
    _HAD_QVS_NOTIFY_ERROR_PVM,
    _HAD_QVS_NOTIFY_ERROR_REMOTE_LIBVIRT,
    _HAD_QVS_NOTIFY_ERROR_GATEWAY,
    _HAD_QVS_NOTIFY_ERROR_QUORUM_WITNES,
    _HAD_QVS_NOTIFY_OK_MIN,
    _HAD_QVS_NOTIFY_OK_ALINKS = _HAD_QVS_NOTIFY_OK_MIN,
    _HAD_QVS_NOTIFY_OK_MLINKS,
    _HAD_QVS_NOTIFY_OK_BLINKS,
    _HAD_QVS_NOTIFY_OK_PVM,
    _HAD_QVS_NOTIFY_OK_REMOTE_LIBVIRT,
    _HAD_QVS_NOTIFY_OK_GATEWAY,
    _HAD_QVS_NOTIFY_OK_QUORUM_WITNES,
    _HAD_QVS_NOTIFY_MAX,
};

#define HAD_QVS_NOTIFY_ERROR_UNKNOWN            (1 << _HAD_QVS_NOTIFY_ERROR_UNKNOWN)
#define HAD_QVS_NOTIFY_ERROR_ALINKS             (1 << _HAD_QVS_NOTIFY_ERROR_ALINKS)
#define HAD_QVS_NOTIFY_ERROR_MLINKS             (1 << _HAD_QVS_NOTIFY_ERROR_MLINKS)
#define HAD_QVS_NOTIFY_ERROR_BLINKS             (1 << _HAD_QVS_NOTIFY_ERROR_BLINKS)
#define HAD_QVS_NOTIFY_RETRY                    (1 << _HAD_QVS_NOTIFY_RETRY)
#define HAD_QVS_NOTIFY_ERROR_PVM                (1 << _HAD_QVS_NOTIFY_ERROR_PVM)
#define HAD_QVS_NOTIFY_ERROR_REMOTE_LIBVIRT     (1 << _HAD_QVS_NOTIFY_ERROR_REMOTE_LIBVIRT)
#define HAD_QVS_NOTIFY_ERROR_GATEWAY            (1 << _HAD_QVS_NOTIFY_ERROR_GATEWAY)
#define HAD_QVS_NOTIFY_ERROR_QUORUM_WITNES      (1 << _HAD_QVS_NOTIFY_ERROR_QUORUM_WITNES)

#define HAD_QVS_NOTIFY_OK_MIN                    (1 << _HAD_QVS_NOTIFY_OK_MIN)
#define HAD_QVS_NOTIFY_OK_ALINKS                 (1 << _HAD_QVS_NOTIFY_OK_ALINKS)
#define HAD_QVS_NOTIFY_OK_MLINKS                 (1 << _HAD_QVS_NOTIFY_OK_MLINKS)
#define HAD_QVS_NOTIFY_OK_BLINKS                 (1 << _HAD_QVS_NOTIFY_OK_BLINKS)
#define HAD_QVS_NOTIFY_OK_PVM                    (1 << _HAD_QVS_NOTIFY_OK_PVM)
#define HAD_QVS_NOTIFY_OK_REMOTE_LIBVIRT         (1 << _HAD_QVS_NOTIFY_OK_REMOTE_LIBVIRT)
#define HAD_QVS_NOTIFY_OK_GATEWAY                (1 << _HAD_QVS_NOTIFY_OK_GATEWAY)
#define HAD_QVS_NOTIFY_OK_QUORUM_WITNES          (1 << _HAD_QVS_NOTIFY_OK_QUORUM_WITNES)

struct qvs_info_t {
    char *domain;
    char *mode;
};

extern struct qvs_info_t qvs_info;

int qvs_info_init(const char *domain, const char *mode);
void qvs_info_free();

void qvs_notify(int notifyevents);
void suicide(int notifyevents);
void notify_or_suicide(int notifyevents);

void had_qvs_notify(int notifyevents);
void had_suicide(int notifyevents);

int notifyevents2response(int notifyevents);
int notifyevents2response_pvm_abnormal(int notifyevents);

#define QVS_NORMAL_SHUTOFF     "true"
#define QVS_ABNORMAL_SHUTOFF   "false"

bool qvs_retrieve_vms_shutoff(const char *domain);


#if defined (__cplusplus)
}
#endif

#endif /* _HAD_QVS_H_ */
