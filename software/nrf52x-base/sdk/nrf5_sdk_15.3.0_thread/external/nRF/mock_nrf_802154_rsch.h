/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_NRF_802154_RSCH_H
#define _MOCK_NRF_802154_RSCH_H

#ifndef __STATIC_INLINE
#define __STATIC_INLINE
#else
#undef __STATIC_INLINE
#define __STATIC_INLINE
#endif
#define SUPPRESS_INLINE_IMPLEMENTATION

#include <nrf_802154_rsch.h>
#undef SUPPRESS_INLINE_IMPLEMENTATION
#undef __STATIC_INLINE
#define __STATIC_INLINE __STATIC_INLINE1

void mock_nrf_802154_rsch_Init(void);
void mock_nrf_802154_rsch_Destroy(void);
void mock_nrf_802154_rsch_Verify(void);




#define nrf_802154_rsch_init_Ignore() nrf_802154_rsch_init_CMockIgnore()
void nrf_802154_rsch_init_CMockIgnore(void);
#define nrf_802154_rsch_init_Expect() nrf_802154_rsch_init_CMockExpect(__LINE__)
void nrf_802154_rsch_init_CMockExpect(UNITY_LINE_TYPE cmock_line);
typedef void (* CMOCK_nrf_802154_rsch_init_CALLBACK)(int cmock_num_calls);
void nrf_802154_rsch_init_StubWithCallback(CMOCK_nrf_802154_rsch_init_CALLBACK Callback);
#define nrf_802154_rsch_uninit_Ignore() nrf_802154_rsch_uninit_CMockIgnore()
void nrf_802154_rsch_uninit_CMockIgnore(void);
#define nrf_802154_rsch_uninit_Expect() nrf_802154_rsch_uninit_CMockExpect(__LINE__)
void nrf_802154_rsch_uninit_CMockExpect(UNITY_LINE_TYPE cmock_line);
typedef void (* CMOCK_nrf_802154_rsch_uninit_CALLBACK)(int cmock_num_calls);
void nrf_802154_rsch_uninit_StubWithCallback(CMOCK_nrf_802154_rsch_uninit_CALLBACK Callback);
#define nrf_802154_rsch_continuous_mode_priority_set_Ignore() nrf_802154_rsch_continuous_mode_priority_set_CMockIgnore()
void nrf_802154_rsch_continuous_mode_priority_set_CMockIgnore(void);
#define nrf_802154_rsch_continuous_mode_priority_set_Expect(prio) nrf_802154_rsch_continuous_mode_priority_set_CMockExpect(__LINE__, prio)
void nrf_802154_rsch_continuous_mode_priority_set_CMockExpect(UNITY_LINE_TYPE cmock_line, rsch_prio_t prio);
typedef void (* CMOCK_nrf_802154_rsch_continuous_mode_priority_set_CALLBACK)(rsch_prio_t prio, int cmock_num_calls);
void nrf_802154_rsch_continuous_mode_priority_set_StubWithCallback(CMOCK_nrf_802154_rsch_continuous_mode_priority_set_CALLBACK Callback);
#define nrf_802154_rsch_continuous_mode_priority_set_IgnoreArg_prio() nrf_802154_rsch_continuous_mode_priority_set_CMockIgnoreArg_prio(__LINE__)
void nrf_802154_rsch_continuous_mode_priority_set_CMockIgnoreArg_prio(UNITY_LINE_TYPE cmock_line);
#define nrf_802154_rsch_continuous_ended_Ignore() nrf_802154_rsch_continuous_ended_CMockIgnore()
void nrf_802154_rsch_continuous_ended_CMockIgnore(void);
#define nrf_802154_rsch_continuous_ended_Expect() nrf_802154_rsch_continuous_ended_CMockExpect(__LINE__)
void nrf_802154_rsch_continuous_ended_CMockExpect(UNITY_LINE_TYPE cmock_line);
typedef void (* CMOCK_nrf_802154_rsch_continuous_ended_CALLBACK)(int cmock_num_calls);
void nrf_802154_rsch_continuous_ended_StubWithCallback(CMOCK_nrf_802154_rsch_continuous_ended_CALLBACK Callback);
#define nrf_802154_rsch_timeslot_request_IgnoreAndReturn(cmock_retval) nrf_802154_rsch_timeslot_request_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void nrf_802154_rsch_timeslot_request_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool cmock_to_return);
#define nrf_802154_rsch_timeslot_request_ExpectAndReturn(length_us, cmock_retval) nrf_802154_rsch_timeslot_request_CMockExpectAndReturn(__LINE__, length_us, cmock_retval)
void nrf_802154_rsch_timeslot_request_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t length_us, bool cmock_to_return);
typedef bool (* CMOCK_nrf_802154_rsch_timeslot_request_CALLBACK)(uint32_t length_us, int cmock_num_calls);
void nrf_802154_rsch_timeslot_request_StubWithCallback(CMOCK_nrf_802154_rsch_timeslot_request_CALLBACK Callback);
#define nrf_802154_rsch_timeslot_request_IgnoreArg_length_us() nrf_802154_rsch_timeslot_request_CMockIgnoreArg_length_us(__LINE__)
void nrf_802154_rsch_timeslot_request_CMockIgnoreArg_length_us(UNITY_LINE_TYPE cmock_line);
#define nrf_802154_rsch_delayed_timeslot_request_IgnoreAndReturn(cmock_retval) nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool cmock_to_return);
#define nrf_802154_rsch_delayed_timeslot_request_ExpectAndReturn(t0, dt, length, prio, dly_ts, cmock_retval) nrf_802154_rsch_delayed_timeslot_request_CMockExpectAndReturn(__LINE__, t0, dt, length, prio, dly_ts, cmock_retval)
void nrf_802154_rsch_delayed_timeslot_request_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t t0, uint32_t dt, uint32_t length, rsch_prio_t prio, rsch_dly_ts_id_t dly_ts, bool cmock_to_return);
typedef bool (* CMOCK_nrf_802154_rsch_delayed_timeslot_request_CALLBACK)(uint32_t t0, uint32_t dt, uint32_t length, rsch_prio_t prio, rsch_dly_ts_id_t dly_ts, int cmock_num_calls);
void nrf_802154_rsch_delayed_timeslot_request_StubWithCallback(CMOCK_nrf_802154_rsch_delayed_timeslot_request_CALLBACK Callback);
#define nrf_802154_rsch_delayed_timeslot_request_IgnoreArg_t0() nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreArg_t0(__LINE__)
void nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreArg_t0(UNITY_LINE_TYPE cmock_line);
#define nrf_802154_rsch_delayed_timeslot_request_IgnoreArg_dt() nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreArg_dt(__LINE__)
void nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreArg_dt(UNITY_LINE_TYPE cmock_line);
#define nrf_802154_rsch_delayed_timeslot_request_IgnoreArg_length() nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreArg_length(__LINE__)
void nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreArg_length(UNITY_LINE_TYPE cmock_line);
#define nrf_802154_rsch_delayed_timeslot_request_IgnoreArg_prio() nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreArg_prio(__LINE__)
void nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreArg_prio(UNITY_LINE_TYPE cmock_line);
#define nrf_802154_rsch_delayed_timeslot_request_IgnoreArg_dly_ts() nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreArg_dly_ts(__LINE__)
void nrf_802154_rsch_delayed_timeslot_request_CMockIgnoreArg_dly_ts(UNITY_LINE_TYPE cmock_line);
#define nrf_802154_rsch_prec_is_approved_IgnoreAndReturn(cmock_retval) nrf_802154_rsch_prec_is_approved_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void nrf_802154_rsch_prec_is_approved_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool cmock_to_return);
#define nrf_802154_rsch_prec_is_approved_ExpectAndReturn(prec, prio, cmock_retval) nrf_802154_rsch_prec_is_approved_CMockExpectAndReturn(__LINE__, prec, prio, cmock_retval)
void nrf_802154_rsch_prec_is_approved_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, rsch_prec_t prec, rsch_prio_t prio, bool cmock_to_return);
typedef bool (* CMOCK_nrf_802154_rsch_prec_is_approved_CALLBACK)(rsch_prec_t prec, rsch_prio_t prio, int cmock_num_calls);
void nrf_802154_rsch_prec_is_approved_StubWithCallback(CMOCK_nrf_802154_rsch_prec_is_approved_CALLBACK Callback);
#define nrf_802154_rsch_prec_is_approved_IgnoreArg_prec() nrf_802154_rsch_prec_is_approved_CMockIgnoreArg_prec(__LINE__)
void nrf_802154_rsch_prec_is_approved_CMockIgnoreArg_prec(UNITY_LINE_TYPE cmock_line);
#define nrf_802154_rsch_prec_is_approved_IgnoreArg_prio() nrf_802154_rsch_prec_is_approved_CMockIgnoreArg_prio(__LINE__)
void nrf_802154_rsch_prec_is_approved_CMockIgnoreArg_prio(UNITY_LINE_TYPE cmock_line);
#define nrf_802154_rsch_timeslot_us_left_get_IgnoreAndReturn(cmock_retval) nrf_802154_rsch_timeslot_us_left_get_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void nrf_802154_rsch_timeslot_us_left_get_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t cmock_to_return);
#define nrf_802154_rsch_timeslot_us_left_get_ExpectAndReturn(cmock_retval) nrf_802154_rsch_timeslot_us_left_get_CMockExpectAndReturn(__LINE__, cmock_retval)
void nrf_802154_rsch_timeslot_us_left_get_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint32_t cmock_to_return);
typedef uint32_t (* CMOCK_nrf_802154_rsch_timeslot_us_left_get_CALLBACK)(int cmock_num_calls);
void nrf_802154_rsch_timeslot_us_left_get_StubWithCallback(CMOCK_nrf_802154_rsch_timeslot_us_left_get_CALLBACK Callback);

#endif
